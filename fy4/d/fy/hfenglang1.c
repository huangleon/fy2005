inherit ROOM;
void create()
{
    set("short", "佻˳���");
    set("long", @LONG
�����Ǹ��������С���Ǹ�����ԡ�ģ����������ʮɫ�Ĳʴ�����ζ�˱ǵĻ�
�꣬������������ض��ǣ�͸������ˮ�����Կ���������������޳��Ĵ��ȣ���
ͦ�����ţ����ںڵĳ���������������
LONG
    );
    set("exits", ([
	"north" : __DIR__"hfeng",
	"south" : __DIR__"hfenglang2",
      ]));
    set("coor/x",-80);
    set("coor/y",-245);
    set("coor/z",0);
    set("map","fysouth");
    setup();
}


/*
int valid_leave(object me, string dir)
{
    if(  dir == "south" && me->query("gender") != "Ů��")
	return notify_fail("����Ů��ԡ�ң�����ȥ��ʲô��\n");
    return 1;
}
*/