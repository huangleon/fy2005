inherit ROOM;
void create()
{
        set("short", "�ھֻ���");
        set("long", @LONG
��ʨ�ھ������������죬��δʧ�ڡ������Ļ���������ѻ���ɽ���ھֵĻ����
������æ���ҵ����ڳ���װ�ػ����Ȼÿ����ƶ��Ѿ�����Ϊ��������æ��������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"goldlion",
]));
        set("objects", ([
        __DIR__"npc/" : 3,
                        ]) );

        set("coor/x",10);
        set("coor/y",50);
        set("coor/z",-300);
        setup();
}

