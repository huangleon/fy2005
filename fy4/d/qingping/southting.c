inherit ROOM;
void create()
{
        set("short", "ƫ��");
        set("long", @LONG
�����������ֻ࣬��һ�ź�ľ���������ź�ľ���ʣ���ʱ���Ϸ������;ߣ�
�������ƽ������ʳ֮��������Ѿ�����ڲ��ã�ǽ��һ����������������"ʳΪ��"��
��ƽ������Խ���ɼ����˵��������ѳ������ס�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ting",
  "east" : __DIR__"kitchen",
]));

	set("coor/x",-50);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
