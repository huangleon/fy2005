inherit ROOM;
void create()
{
        set("short", "�ײ�");
        set("long", @LONG
�ײ�������ʪ�������˱ǡ����ϲյĸ������������Ǻϡ�һյ�����ĵ�������
�����ҡ�ڶ�����֨֨�����ı���������壬�ƺ�����ˮ����������յױ��䣬��
�����Ըе���ˮ��������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"secret_room",
  "east" : __DIR__"troom",
]));

	set("coor/x",-55);
	set("coor/y",15);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
