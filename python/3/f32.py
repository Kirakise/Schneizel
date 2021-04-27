class C32:
    state = 'A'
    def __init__(self):
        self.state = 'A'

    def apply(self):
        if self.state == 'B':
            self.state = 'C'
            return 1
        elif self.state == 'C':
            self.state = 'F'
            return 6
        else:
            raise(RuntimeError)
    def speed(self):
        if self.state == 'A':
            self.state = 'B'
            return 0
        elif self.state == 'C':
            return 5
        elif self.state == 'B':
            self.state = 'D'
            return 3
        elif self.state == 'E':
            self.state = 'F'
            return 8
        else:
            raise(RuntimeError)
    def slur(self):
        if self.state == 'B':
            return 2
        elif self.state == 'C':
            self.state = 'D'
            return 4
        elif self.state == 'D':
            self.state = 'E'
            return 7
        else:
            raise(RuntimeError)
