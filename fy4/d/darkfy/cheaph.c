inherit ROOM;
void create()
{
        set("short", "���ι�");
        set("long", @LONG
һ���ª�ģ��������������ĵͰ�С���������ǽ�������ѷ죬�����Ͻ�һֱ�ѵ���
�ߵ�ǽ���������һ�ź�������Ϊһ���������������������������ȡů����ͷ
���ź����ʣ�������ֽһ�ţ��۸���ƽ����Ů���ٽ��ˣ�ˡ����Ǯ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud3",
]));
        set("objects", ([
        __DIR__"npc/" : 1,
                        ]) );
        set("no_preach",1);
        set("coor/x",-30);
        set("coor/y",-9);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
