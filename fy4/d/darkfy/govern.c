inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�����ǳ�͢���裬���Ƴ���ľ��׶�������������״��������������һ�ž�
��ľ���������и�С��Ͱ��������ż�����֪����ӡ����ǩ��ľ�����̫ʦ��������
ѩ��Ƥ���κ������Ϻ�������ͼ����������ң�
[31m
				�������
[37m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud2",
  "east" : __DIR__"shufang",
]));

        set("coor/x",-21);
        set("coor/y",-10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
