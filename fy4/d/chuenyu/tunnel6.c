
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
//  "north" : __DIR__"tortureroom2",
  "east" : __DIR__"tunnel5",
  "west" : __DIR__"tunnel2",
]));

	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",5);
	setup();
        replace_program(ROOM);

}

