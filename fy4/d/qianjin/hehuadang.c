inherit ROOM;
void create()
{
        set("short", "�ɻ���");
        set("long", @LONG
��԰���棬����һ������������ɻ�����ÿ����ʱ�����̼䷢����������ʤ����
�غ����ܽ�أ���������ɫ������ʢ��֮�գ������������ף�����Ϯ�ˣ�С�۵���
���⣬������������б��΢���������ɣ��ݺ���ɡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"hehuadang1",
  "east" : __DIR__"bamboo_bridge3",
]));
	set("outdoors","fengyun");
	set("coor/x",-25);
	set("coor/y",-5);
	set("coor/z",0);
	set("coor/x",-25);
	set("coor/y",-5);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
