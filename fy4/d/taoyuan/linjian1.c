inherit __DIR__"no_killing_place";
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
ɽ���������£��������¡����µ�����ϸ��ǡ��û�㣬���������������
�����Ż������㣬��ǰ�Ĵ������м�ֻ��������ˣ����Զ������һȺ������ּ���
Ծ��Ϸ�������һ�г�������͵���Ϣ��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"linjian",
    ]));
    set("objects", ([
        __DIR__"npc/monkey1": 1,
//        __DIR__"npc/monkey2" : 1,
    ]) );
	set("no_magic", 1);
   	set("outdoors","taoyuan");
	set("coor/x",10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
    replace_program( __DIR__"no_killing_place");
}


