inherit ROOM;
void create ()
{
        set ("short", "����С·");
        set ("long", @LONG
����һ��������ʪ��С·��λ�ڳ����֮���ϣ���Χɢ����һЩ��ԫ�ϱڣ�·
���Ӳݴ��������ڹٸ����ٹ���������ΰ�����ʮ�ֺá������ǳ��ƵĻ�ɫ����
��һ˿������������ȥ��һ����Ȼ�Ŀ���ƽ̨������ǰ��
LONG);
        set("exits", ([ //sizeof() == 4
                "north" : __DIR__"yinroad2",
        "westup" : __DIR__"bigstage",
        ]));
        set("type", "road");
       set("outdoors", "wolfmount");
	set("coor/x",30);
	set("coor/y",70);
	set("coor/z",-60);
        setup();
	replace_program(ROOM);
}
