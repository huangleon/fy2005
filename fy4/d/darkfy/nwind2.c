inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����Ƿ��Ƴ������ֵ������ֵ�֮һ���ֵ����������������ﲻ�����ֵ����Ե�
���ڶ࣬������¡�����������Ȳ�������Ů���ǵĽ�Ц�������������������ζ����
�Ʋ˵���ζ������Ů�����ϵĻ���ζ������ʱ�Ĵ������ԣ�������Ŀѣͷ�εĸо���
��ֶ����Ʈ�㻨�������������֬����ӳ���ԡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nwind1",
  "north" : __DIR__"nwind3",
  "east" : __DIR__"pxhdian",
  "west" : __DIR__"qcyzdian",
]));
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",20);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
