inherit ROOM;
void create()
{
        set("short", "�޻���");
        set("long", @LONG
ÿ���������䣬�������ٶ��ᵽ��������Լ��Ķ�����
������һ����������ϰ�����Ƴ����·������������·�
���ι̶��Ҳ��ѿ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ecloud4",
]));
        set("objects", ([
        "/d/fy/npc/mianhua" : 1,
                        ]) );

        set("coor/x",40);
        set("coor/y",10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
