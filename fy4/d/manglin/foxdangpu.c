//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
	set("short", "���ǵ���");
	set("long", @LONG
�˵�����רΪ����ĺ��������裬�Է�����ͷ������οͺͼ��ڷ����Ķ�ͽ����
�����̿���Ҳ����������������Я���Ĺ�����Ʒ�䵱�ڴˣ��ȳ�������֮������
�أ��Է��ں��϶�ʧ����Ȼ��������Ĺ�����Ҳ�������˵䵱�������������Ǹ���֮
�����ʹ͵�С����������̹����ƣ�����һ�顣
LONG
	   );
	set("exits", 
	   ([
	     "west" : __DIR__"southsearoad",
	    ]) );
	set("item_desc", 
	   ([
	     "sign": @TEXT
���ǵ��̣�Ŀǰ�����ṩ�ķ����У�

pawn	    �䵱���
value       ���ۻ��
sell        ���ϻ��
redeem      ��ػ��

ͯ�����ۣ���ӭ�ٴι��ٱ����̡�^_^
TEXT
	    ]) );
	set("objects", 
	   ([
	     AREA_BAIYUN"npc/hockowner" : 1,
	    ]) );
	set("coor/x",70);
	set("coor/y",-230);
	set("coor/z",10);
	setup();
}