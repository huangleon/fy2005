inherit ROOM;
void create()
{
        set("short", "�����ײĵ�");
        set("long", @LONG
���ſڵ������Ǽ����ѱ�������ɹ�ñ�����ɫ�Ļ�Ȧ����ڵĵ��Ϸ��ż��ڴ���ã�
����û������ı�Ƥ�ײġ� �����ǽ�����ҵĹ��ż���ֽǮ��ֽ����ǽ�Ƿ���һ����
�õĺ�ľ�ײģ����׸��ƺ���û�иǺá�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud4",
]));
        set("objects", ([
        __DIR__"npc/" : 1,
                        ]) );

        set("coor/x",-40);
        set("coor/y",-10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
