inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ��ǳ����صķ��䣬û�д�����ֻ����һ�������������������һ��
��ҹ��Ĺ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  			"up": __DIR__"tianti1",
  			"north": __DIR__"feng",
		]));

		set("coor/x",0);
		set("coor/y",-10);
		set("coor/z",0);
		setup();
}
