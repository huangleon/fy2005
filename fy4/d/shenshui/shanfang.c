// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ŷ�");
        set("long", @LONG
�ŷ�����ɾ��쳣����Ȼû��һ˿�̳�����ɫҲ�Ƿ���ľ��£��ŷ��м���һ
�Ŵ����ӣ���������С��һ�ߵ���һ��׼���Ų��ȣ�û�뵽������η֮�绢�İ�ˮ
��Ů��Ȼ��ô�Ļ��ÿɰ����ɼ���������δ�ؾ�ʵ��
LONG
        );
   set("exits", ([ 
      "west" : __DIR__"gong",
   ]));
   set("objects", ([
      __DIR__"obj/table": 1,
      __DIR__"npc/qinggirl": 3,
   ]) );
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void reset()
{
   object *inv;
   object item, table;
   ::reset();

   table = present("table", this_object());
   inv = all_inventory(table);
   if( !sizeof(inv)) {
      item = new(__DIR__"obj/tangbao");
      item->move(table);
      item = new(__DIR__"obj/douya");
      item->move(table);
   }
}


