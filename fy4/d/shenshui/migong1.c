// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�޶�");
        set("long", @LONG
�ղź������ã�������ȴ�����ڵ����������ǻ�Ʒ���Ĺ��ߣ��㲻�ɾ���
���ȣ�����Խ��Խ�ȣ��ƺ��л��ڼ尾���㣬���˼������ܾ�ɫû�иı䣬����
��ʱ������Ů������������������Χ���ȵ���ʯ���㲻��Խ��Խ���
LONG
        );
   set("exits", ([ 
      "south": __DIR__"migong.c",
      "north": __DIR__"migong2.c",
   ]));
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",-20);
	setup();
        replace_program(ROOM);
}
