// inn.c

inherit ROOM;


void create()
{
    set("short", "ǧ������");
    set("long", @LONG
�˵������Ϸ��ֶ����ǧ��¥���衣�Է�����ͷ������ο͡�ǧ��¥�Ĺ���
��Ҳ�����������䵱�������������Ǹ���֮�����ʹ͵�С��������˵�����Ȼ
��ǧ��¥��������ȴͯ�����ۡ����̹����ƣ�����һ�顣
LONG
    );

    set("exits", ([
	"north"      : __DIR__"wcloud2",
	"west"      : __DIR__"qianyin_neitang",
      ]) );
    set("item_desc", ([
	"sign": @TEXT
������ǧ�����̣�Ŀǰ�����ṩ�ķ����У�

pawn	    �䵱���
value       ���ۻ��
sell        ���ϻ��
redeem      ��ػ��

TEXT
      ]) );


    set("objects", ([
	__DIR__"npc/hockowner" : 1,

      ]) );


    set("coor/x",-120);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fywest");
    setup();
}
