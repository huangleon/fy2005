inherit ROOM;
void create()
{
        set("short", "�����ۼװ�");
        set("long", @LONG
��ɫ���̣���ɫ������΢���������羰���ˡ�һ������ȭ�о��������Ů��
�Ľ�Ц����ʱ�ĴӴ����д���������ϸ�����������ƺ��������ŵ͵͵ı���֮����
�봬�ϵĻ���Ц�Ｋ����Ǣ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"taban",
  "north" : __DIR__"boat1",
]));
	set("outdoors","fengyun");
	set("coor/x",-60);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
