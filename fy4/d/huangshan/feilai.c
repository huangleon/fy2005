// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����ʯ");
        set("long", @LONG
��ƽ̹��ɽ��֮�ϣ�ͻȻð��һ��ʯͷ���ƺ����˷���һ˵�����ʵ�����Խ�
�͡�ʯ��⻬���������֡�����ʯ����Զ��ʯͷ���ϴ���ϸ������ҡ�β�ֹ��ʵ����
�˷�����˼��
LONG
        );
    set("exits", ([ 
  		"north" : __DIR__"guangming",
	]));
    
    set("outdoors", "huangshan");
	set("coor/x",-90);
	set("coor/y",-20);
	set("coor/z",30);
	setup();
}

