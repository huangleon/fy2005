inherit ROOM;
void create()
{
        set("short", "ǰ��԰");
        set("long", @LONG
ǧ��¥����֮����������Լ�һ�ߣ��ı߻������࣬��Ψ��ĵ����ʤ���ǻ���
��Ѱ����¥��֮�࣬�ˡ�Ҧ�ơ���κ�ϡ�������Ʒ��һ����ֵ��ǧ���ǻ���������
�Ŷ��棬��Χ�Ժ�ʯ��֮���仨���絤�̣���ɫ���ã��⻪��Ŀ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"pingfeng",
  "southwest" : __DIR__"bamboo_bridge1",
  "north" : __DIR__"garden1",
  "south" : __DIR__"garden2",
]));
	set("outdoors","fengyun");
	set("coor/x",-5);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-5);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
