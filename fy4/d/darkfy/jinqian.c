inherit ROOM;
void create()
{
        set("short", "�������Ժ");
        set("long", @LONG
��Ժ���������壬Ҳ���ĳ��档Ժ�е������ڵ����ϳ�������Ӱ�ӡ�ż��������У�
����������ļž���΢�紵������Ҷ�趯��������ɳɳ������������ɳ�ĵ��������ݻ�
����Ҷ��������ɫ����Ӱ�������Ľ�����������֡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"swind2",
  "west" : __DIR__"jting",
]));
        set("outdoors", "fengyun");
        set("coor/x",-10);
        set("coor/y",-20);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
