
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����ںڰ������������ֲ�����ָ��Ψһ�Ĺ�������ǽ�Ϻ������������͵ơ�
���Ϻ�ǽ�ϲ����˰���ɫ��Ѫ�ۣ�ɢ�����������������ϴ����İ������������ĵ�
����ص�������ë����Ȼ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
//  "south": __DIR__"tunnel5",
  "north" : __DIR__"tunnel2",
]));
        set("objects", ([
                __DIR__"npc/highrat": 1 
	]) );

	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",5);
	setup();
        replace_program(ROOM);
}

