inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����Ƿ��Ƴ������ֵ������ֵ�֮һ���ֵ����������������ﲻ�����ֵ����Ե�
���ڶ࣬������¡�����������Ȳ�������Ů���ǵĽ�Ц�������������������ζ����
�Ʋ˵���ζ������Ů�����ϵĻ���ζ������ʱ�Ĵ������ԣ�������Ŀѣͷ�εĸо���
��������������̺Ͷ��ߵĽ�ʨ�ھ�ңң������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nwind3",
  "north" : __DIR__"nwind5",
  "east" : __DIR__"goldlion",
  "west" : __DIR__"stopwin",
]));
        set("outdoors", "fengyun");
        set("objects", ([
        __DIR__"npc/dtz": 5,
                        ]) );
        set("coor/x",0);
        set("coor/y",40);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
