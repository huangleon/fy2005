// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "Ҵ��");
        set("long", @LONG
��ɽ�����Ҵ��һ����Ӳɽǽ�������Ͱ���ǽ������������Ȼ�����ߴ�ȴҲ
�������£����������ֱͨɽ�ţ�������ֱ���˵أ���������Ҫ��������Ʒ���
�˴����롣    
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"gulou",
  		"southeast" : __DIR__"yonglu",
]));
        set("objects", ([
                __DIR__"obj/mache" : 1,
       	]) );
        set("outdoors", "shaolin");
	set("coor/x",-10);
	set("coor/y",-70);
	set("coor/z",-10);
	setup();
}


void reset()	{
	object ob1,ob2, con;
	object *inv;
	int i;
	
	::reset();
	ob1 = new(AREA_WANMEI"obj/vege");
	ob2 = new (AREA_WANMEI"obj/drywoods");
	
	con = present("mache",this_object());
	if (con)	{
		inv=all_inventory(con);
		if (sizeof(inv)) {
			for (i=0;i<sizeof(inv);i++)
			if (inv[i]->query("id")=="woods" || inv[i]->query("id")=="vegetable")
				destruct(inv[i]);
		}
		ob2->set_amount(random(5)+1);
		ob1->move(con);
		ob1 = new(AREA_WANMEI"obj/vege");
		ob1->move(con);
		ob1 = new(AREA_WANMEI"obj/vege");
		ob1->move(con); 
		ob2->move(con);
	}
}
