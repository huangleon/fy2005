
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
        set("exits", ([ /* sizeof() == 3 */
  		"southeast" : __DIR__"dungeon",
  		"south"   : __DIR__"tunnel2",
]));

	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",5);
	setup();
}

