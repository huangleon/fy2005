inherit ROOM;
void create()
{
        set("short", "�ͷ���");
        set("long", @LONG
��Ǯ��������������̰���ܻߣ��������ǣ���Ϸ��Ů֮��ͽ�������������ܵ�Ӧ
�е��Ʋá����о޹��ڽ�Ǯ��ģ������������ܵ��������ʹͺ���Ρ�������������
����            �ͷ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"jhuang",
]));
        set("objects", ([
        __DIR__"npc/" : 1,
                        ]) );

        set("coor/x",-30);
        set("coor/y",-10);
        set("coor/z",-300);
        setup();
}



