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
  "south" : __DIR__"boat",
  "north" : __DIR__"boat2",
]));
	set("outdoors","fengyun");
	set("coor/x",-60);
	set("coor/y",15);
	set("coor/z",-1);
	setup();
        replace_program(ROOM);
}
