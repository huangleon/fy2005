// Room: /d/oldpine/secrectpath1.c

inherit ROOM;

void create()
{
        set("short", "����ͨ��");
        set("long", @LONG
��������վ��һ����ʯͨ��֮�У����ϱ���������������ˮ�����ұ���������
�����̦��һ�ɶ���ӱ��ߴ���������ʲ��Ұ�ޣ�Ҳ����û�ͷ��ȥ�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	  "south" : __DIR__"passage",
	]));

	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
