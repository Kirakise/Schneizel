import struct

def f31(x):
    res = {}
    res['A1'] = '';
    size = x[4]
    + x[5] * 16
    + x[6] * 16 * 16
    + x[7] * 16 * 16 * 16
    addr = x[8] + x[9] * 16
    for i in range(addr, addr + size):
        res['A1'] += chr(x[i]);

    res['A2'] = struct.unpack('h', x[10:12:])[0]
    res['A3'] = struct.unpack('d', x[12:20:])[0]
    res['A4'] = struct.unpack('h', x[20:22:])[0]
    res['A5'] = []
    for i in range(5):
        res['A5'].append({})
        res['A5'][i]['B1'] = struct.unpack('f', x[22 + 6 * i : 26 + 6 * i :])[0]
        res['A5'][i]['B2'] = struct.unpack('h', x[26 + 6 * i : 28 + 6 * i :])[0]
    res['A6'] = struct.unpack('B', x[52 : 53:])[0]
    res['A7'] = {}
    res['A7']['C1'] = struct.unpack('b', x[53 : 54:])[0]
    res['A7']['C2'] = {}
    res['A7']['C2']['D1'] = struct.unpack('b', x[54:55:])[0]
    res['A7']['C2']['D2'] = struct.unpack('d', x[55:63:])[0]
    size = struct.unpack('H', x[63:65:])[0];
    addr = struct.unpack('I', x[65:69:])[0];
    res['A7']['C3'] = []
    for i in range(size):
        res['A7']['C3'].append(struct.unpack('I', x[addr + 4 * i: addr + 4 + 4 * i:])[0])
    res['A7']['C4'] = []
    for i in range(5):
        res['A7']['C4'].append(struct.unpack('B', x[69 + i : 70 + i:])[0])
    res['A7']['C5'] = struct.unpack('Q', x[74:82:])[0]
    size = struct.unpack('H', x[82 : 84:])[0]
    addr = struct.unpack('I', x[84 : 88:])[0]
    res['A7']['C6'] = []
    for i in range(size):
        res['A7']['C6'].append(struct.unpack('B', x[addr + i: addr + 1 + i :])[0])
    res['A8'] = struct.unpack('Q', x[88 : 96:])[0]
    return res
