
inherit ROOM;

void create()
{
        set("short", "ޒ��ʯ");
        set("long", @LONG
ɽ��·ת���ֿ�ʼ�˵�ɽ�ĵ�·��ͻȻ��ǰ·�߳���һ���ʯ��ʯ�����ɣ�һ
��Ƚ�ƽ��������׭����̡�ޒ��ʯ�����֡��ɡ�ޒ��ʯ��ʰ���������ۣ�һ����խ
��ʯ���У�����370���̨�ף����ǻ�ɽ��һ�գ�ǧ�ߴ���
LONG
        );
    set("exits", ([ 
  		"northdown" : __DIR__"qingke",
		"southup" : __DIR__"qianchi",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-15);
	set("coor/y",-40);
	set("coor/z",10);
	setup();
    replace_program(ROOM);
}

