inherit ROOM;
void create()
{
        set("short", "���᷿");
        set("long", @LONG
���������������۲�ͷ���ճ���ȭ�оƵ��᷿�����м�����ͨ�̿ɹ���������
Ϣ�����ź�ľ����̯���˺ȿյľƴ���̳���и����ˣ������Ǽ���һ��Ũ�ҵľ���
�Ĵ�������ƽ����֪�����ŵĽ�ʦүҲϲ��������Ⱦ����ģ������ǲ����飬��
���۰���̧�ؼ���Ҳ����ÿ�����еĹ��£�;
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"east" : __DIR__"govern",
	]));
        set("objects", ([
        	__DIR__"npc/jiang" : 1,
        ]) );

	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}


