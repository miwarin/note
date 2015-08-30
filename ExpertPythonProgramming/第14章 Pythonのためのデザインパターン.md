## 14.1.1 Singleton パターン


    #!/usr/bin/python
    # -*- coding: utf-8 -*-
    
    """
    14.1.1 Singleton パターン p.375
    """
    
    class Borg(object):
        _state = {}
        def __new__(cls, *args, **kw):
            ob = super(Borg, cls).__new__(cls, *args, **kw)
            ob.__dict__ = cls._state
            return ob
    
    
    class MyClass(Borg):
        a = 1
    
    class MyOtherClass(MyClass):
        b = 2
    
    one = MyClass()
    two= MyClass()
    two.a = 3
    print one.a
    
    three = MyOtherClass()
    print three.b
    
    print three.a
    
    three.a = 2
    
    print one.a


    3
    2
    3
    2



## 14.3.1 Observer パターン 

    #!/usr/bin/python
    # -*- coding: utf-8 -*-
    
    """
    14.3.1 Observer パターン  p.384
    """
    
    class Event(object):
        _observers = []
        
        def __init__(self, subject):
            self.subject = subject
            
        @classmethod
        def register(cls, observer):
            if observer not in cls._observers:
                cls._observers.append(observer)
                
        @classmethod
        def unregister(cls, observer):
            if observer in cls._observers:
                self._observers.remove(observer)
    
        @classmethod
        def notify(cls, subject):
            event = cls(subject)
            for observer in cls._observers:
                observer(event)
    
    class WriteEvent(Event):
        _observers = []
        def __repr__(self):
            return "WriteEvent"
    
    def log(event):
        print "%s was written" % event.subject
    
    
    class AnotherObserver(object):
        def __call__(self, event):
            print "Yeah %s told me !" % event
    
    
    def main():
        WriteEvent.register(log)
        WriteEvent.register(AnotherObserver())
        WriteEvent.notify("a given file")
    
    
    if __name__ == "__main__":
        main()


    a given file was written
    Yeah WriteEvent told me !


## 14.3.2 Visitor パターン 1

    #!/usr/bin/python
    # -*- coding: utf-8 -*-
    
    """
    14.3.2 Visitor パターン p.386
    """
    
    
    class MyClass:
        value = 1
        def __str__(self):
            return str(self.value)
    
    
    class Printer(object):
        def visit_int(self, ob):
            print 'int %s' % ob
    
        def visit_str(self, ob):
            print 'str: %s' % str(ob)
            
        def visit_list(self, ob):
            print 'list content: '
            print str(ob)
    
        def visit_dict(self, ob):
            print 'dict keys: %s' % ','.join(ob.keys())
    
        def visit_MyClass(self, ob):
            print 'MyClass %s' % ob
    
    
    def visit(visited, visitor):
        cls = visited.__class__.__name__
        meth = 'visit_%s' % cls
        method = getattr(visitor, meth, None)
        if method is not None:
            method(visited)
    
    def main():
        visit([1, 2, 5], Printer())
        visit( {'one' : 1, 'two' : 2, 'three' : 3}, Printer())
        visit('hoge', Printer())
        visit(99, Printer())
        visit(MyClass(), Printer())
    
    
    if __name__ == "__main__":
        main()



    list content:
    [1, 2, 5]
    dict keys: three,two,one
    str: hoge
    int 99
    MyClass 1


## 14.3.2 Visitor パターン 2

    #!/usr/bin/python
    # -*- coding: utf-8 -*-
    
    """
    14.3.2 Visitor パターン p.387
    """
    
    
    import os
    
    def visit(directory, visitor):
        print directory
        for root, dirs, files in os.walk(directory):
            for file in files:
                print file
                ext = os.path.splitext(file)[-1][1:]
                meth = getattr(visitor, ext, None)
                if meth is not None:
                    meth(os.path.join(root, file))
    
    class FileReader(object):
        def pdf(self, file):
            print 'processing %s' % file
            
        def jpg(self, file):
            print 'processing %s' % file
    
    def main():
        visit('/home/music/image/', FileReader())
    
    if __name__ == "__main__":
        main()
    
