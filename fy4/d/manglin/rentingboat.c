//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������ר��Ϊ��λ������ʿ�ṩ���ּ۸��������һ���ĺ�������ҵ�񣬾�
��ϸ�����λ�ο��۸��ơ��ڴ��еĴ����м���м۸��ƣ�����һ�顣
LONG
	   );
	set("exits", 
	   ([
	     "west" : __DIR__"southsearoad1",
	    ]) );
	set("item_desc", 
	   ([
	     "sign": @TEXT
���ֺ��ṩ���⴬�����У�

ľ�� (raft)��������㣬�������ˣ��ع���Ȼ�����ӷ��飬ֻ��1 ��������
С�� (boat)��һҶ���ۣ��沨���������˺ϳˣ��������飬ֻ��5 ��������

��������ĺ��𿨵ĳ����ߣ�ֻ�������ƹ������Ӧ�ġ�ľ������С�ۡ�
���ֱ�Ӵ��Ϲ�Ǯׯת�ˡ�

���������ͨ�˿ͣ���ֱ�ӽ���𽻸����ƹ��ɡ�

TEXT
	    ]) );
	set("objects", 
	   ([
	     AREA_BAIYUN"npc/boatowner" : 1,
	    ]) );
	set("coor/x",70);
	set("coor/y",-240);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}

/*
//�����ṩ���⴬�����У�
//
//ľ�� (raft)		  10 ��������
//С�� (boat)		 100 ��������
//���� (ship)		1000 ��������
//
//��ӭ�ٴι��ٱ��ꡣ*/
