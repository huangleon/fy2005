// �ص�
inherit ROOM;
void create()
{
        set("short", "�ص�");
        set("long", @LONG
������ĵص����㲻֪��Ҫ����ò��ܳ�ȥ��
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"didao",
  "westdown" : __DIR__"didao2",
]));
	set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",-40);
	setup();
}
int valid_leave(object me, string dir)
{
        if( userp(me) )
                    message_vision("$N�ֽŲ��ã���ص����ȥ\n",me);

        return 1;
}
void init()
{
	add_action("do_go","go");

}

int do_go()
   {
   if(random(5)){
     message_vision("$N�ֽŲ��ã���ص����ȥ\n",this_player());
     this_player()->move(this_object());
     return 1;
   }
}

