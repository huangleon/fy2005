inherit ROOM;
void create()
{
        set("short", "�ھֳ���");
        set("long", @LONG
��ʨ�ھֶԻ����ʮ�ֿ��������ÿ����н�𣬶��һ�����ס��������ǻ����
һ�����͵ĵط���������ǽ�Ϲ����˹���ư�裬����һЩ��ɵ�±ζ�������з���һ
�ų�̨����̨����Χ���ż������ʡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"goldlion",
]));
        set("objects", ([
        __DIR__"npc/goldcook" : 1,
                        ]) );

        set("coor/x",10);
        set("coor/y",30);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
