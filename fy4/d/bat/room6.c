inherit ROOM;
void create()
{
        set("short", "���䳡");
        set("long", @LONG
����һ��������䳡��ʮ�˰����������ȫ�����м��������õ�ľ׮��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
       "east" : __DIR__"room7",
	]));
    set("objects", ([
      __DIR__"obj/wood": 1,
	  ]) );
	set("coor/x",-60);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
