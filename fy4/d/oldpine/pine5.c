// Room: /d/oldpine/pine1.c

inherit ROOM;
string *names=({
	__DIR__"pine6",
	__DIR__"pine2",
	__DIR__"pine5",
	__DIR__"pine4",
} );

void create()
{
        set("short", "������");
        set("long", @LONG
��������վ��һ�����������....����һ��������....����֪������࣬ï
�ܵ������ڱ���������գ�ʹ��������Ū���������������֮ǰ�Ͻ�������·
��ȥ�ɡ�
LONG
        );
        set("outdoors", "oldpine");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",20);
	setup();
}

void reset()
{
	int i,j;
	string temp;
	::reset();
	for (i=0;i<=3;i++)
	{
		j=random(4);
		temp=names[j];
		names[j]=names[i];
		names[i]=names[j];
		names[i]=temp;
	}
	set("exits", ([
		"north" : names[0],
		"south" : names[1],
		"east" : names[2],
		"west" : names[3],
	]));
}

int valid_leave(object me, string dir)
{
        write("��ʵ��Ū���������....");
        switch(dir) {
                case "north":   write("����....�����������أ�....");    break;
                case "east":    write("����....����....");      break;
                case "south":   write("�ϱ�....�������ϱߣ�....");      break;
                case "west":    write("����....��....");        break;
                default:
                        write("������������....");
        }
        write("�����������ɡ�\n");
        return 1;
}
