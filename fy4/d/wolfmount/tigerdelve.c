inherit ROOM;

void create()
{
	set("short", "��Ѩ");

	set("long", @LONG
һ���ܿ�����ʯ�������кܰ���������һƬ������ʲô��������������ʱ����
������ɫ���׹⣬������΢������Ĺ��ߣ��㳯������ȥ�����ض��Ǹ��õ��⣬��
�õ�ʬ�������˵Ŀݹǡ�
LONG);

	set("type","street");
	set("exits",([
		"out":__DIR__"18pan1",
	]) );
	set("indoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/wuyi":1,
     		__DIR__"npc/longzi":1,
		__DIR__"obj/tigerbone":2,
    	]) ); 
	set("coor/x",10);
	set("coor/y",50);
	set("coor/z",-30);
	setup();
}

void reset(){
        object item;
        int i;
        ::reset();
      
	if(!present("tiger bone", this_object())){
                for (i=1; i<=2 ; i++) {
                	item = new(__DIR__"obj/tigerbone");
	                if(objectp(item)){
                        item->move(this_object());
                	}
	        }
        }
        return;
}       