inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���¾���ר�Ÿ����������ܶ�İ�ȫ���������ˣ���Ҫ�������ǵļ�졣��������
���ְ���Ϣ�����ڡ������м���С��������С����ÿ�Ŵ�ͷ����С���������Ƕ��ѱ�
�����ڹ��ϣ�һ���֣����ǾͿ��������ٶȰγ��Լ��ı�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jting",
  "south" : __DIR__"jbang",
]));
        set("objects", ([
        __DIR__"npc/" : 3,
                        ]) );

        set("coor/x",-20);
        set("coor/y",-35);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}