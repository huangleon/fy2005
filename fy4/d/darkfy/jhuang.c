inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���¾���ר�Ÿ����Ǯ���ܶ�İ�ȫ���������ˣ���Ҫ�������ǵļ�졣��������
���ְ���Ϣ�����ڡ������м���С��������С����ÿ�Ŵ�ͷ����С���������Ƕ��ѱ�
�����ڹ��ϣ�һ���֣����ǾͿ��������ٶȰγ��Լ��ı��С�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jting",
  "east" : __DIR__"tang1",
  "west" : __DIR__"tang2",
  "north" : __DIR__"tang3",
]));
/*        set("objects", ([
        __DIR__"npc/" : 3,
                        ]) );
*/
        set("coor/x",-20);
        set("coor/y",-10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
