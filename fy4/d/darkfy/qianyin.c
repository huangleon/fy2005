// inn.c

inherit ROOM;


void create()
{
	set("short", "ǧ������");
	set("long", @LONG
�˵������Ϸ��ֶ����ǧ��¥���衣�Է�����ͷ������ο͡�ǧ��¥�Ĺ�����
Ҳ�����������䵱�������������Ǹ���֮�����ʹ͵�С��������˵�����Ȼ��ǧ
��¥��������ȴ��ͯ�����ۡ����̹����ƣ�����һ�顣
LONG
	);
	
	set("exits", ([
		"west"    	: __DIR__"swind4",
	]) );
        set("item_desc", ([
                "sign": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

pawn	    �䵱���
value       ���ۻ��
sell        ���ϻ��
redeem      ��ػ��

TEXT
        ]) );


	set("objects", ([
		__DIR__"npc/hockowner" : 1,

			]) );


	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",-300);
	setup();
}
