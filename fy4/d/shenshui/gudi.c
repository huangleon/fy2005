// TIE@FY3 ALL RIGHTS RESERVED
//XXDER
inherit ROOM;
void create()
{
        set("short", "�ȵ�");
        set("long", @LONG
Զ�����ܣ����ɿ�̾����֮���棬ԭ�����ﱻȺ�廷�ƣ��Ҽ��ͣ��ƺ���
�ڵ�ƽ֮�£����Ʊ�����̤��һ�Ŷ��ɵġ������Ǻ��İ��ƣ�������������
�����ϸ��ӣ������Ѽ������
LONG
        );
   set("exits", ([ 
      "northeast" : __DIR__"tianti1",
      "south" : __DIR__"dongkou",
   ]));

   set("outdoors","shenshui");
	set("coor/x",-50);
	set("coor/y",-130);
	set("coor/z",20);
	setup();
   replace_program(ROOM);
}
