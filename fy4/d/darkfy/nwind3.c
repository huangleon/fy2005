inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����Ƿ��Ƴ������ֵ������ֵ�֮һ���ֵ����������������ﲻ�����ֵ����Ե�
���ڶ࣬������¡�����������Ȳ�������Ů���ǵĽ�Ц�������������������ζ����
�Ʋ˵���ζ������Ů�����ϵĻ���ζ������ʱ�Ĵ������ԣ�������Ŀѣͷ�εĸо���
��������ǽ������ã���ֵĶ�������ר��Ϊǧ��С��׼����佻��á�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nwind2",
  "north" : __DIR__"nwind4",
  "east" : __DIR__"hfeng",
  "west" : __DIR__"jlong",
]));
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",30);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
