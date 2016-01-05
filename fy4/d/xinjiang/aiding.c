/* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����������в����ɽ�����п����ڳ�ɽ�����о�������ɽ�������п�ķ����
ɽ����Ϊ�¹��������󲿷��������粨�ĸɺԺ��ף���Ŀ�������׾�Ө��[37m�ΰ�[32m��
���������������⣬���ƺ�ҹ���յ��¹⣬������������
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"tulufan",
  "westdown" : __DIR__"pubu",
]));
        set("objects", ([
        __DIR__"npc/saltboss" : 1,
                        ]) );
        set("item_desc", ([
	           "�ΰ�": "����һ���ΰ��̸����Ѿ��ɺԵĺ��ס�\n",
	           "yanba": "����һ���ΰ��̸����Ѿ��ɺԵĺ��ס�\n",
	           "salt rock": "����һ���ΰ��̸����Ѿ��ɺԵĺ��ס�\n",
	           "salt": "����һ���ΰ��̸����Ѿ��ɺԵĺ��ס�\n",
        ]));
	//set("no_pk",1);
	
	
        set("outdoors", "xinjiang");
		set("coor/x",50);
		set("coor/y",-60);
		set("coor/z",10);
		setup();
}


void dig_notify()
{
     object me, salt;
     me = this_player();     
          
     message_vision("$N�ں��׿�ʼæ�ҵ��ھ�������\n",me);
     
    if (!me->query_temp("marks/xj_noticed_salt")) {
    	tell_object(me,"����Ŀ�ĵ����˰��죬�����治�ã�ʲô��û���ҵ���\n");
    	return;
    }
     
     if(query("already")) {
     	tell_object(me,"���ڶ����ΰͶ��Ѿ��������ˡ�\n");
     	return ;
     }
     
     message_vision("�ϣ�����һ�����ٿ����ϵ��ΰͱ�$N����һС�顣\n", me);
     salt = present("salt rock", this_object());
     if(!objectp(salt)) {
        salt = new(__DIR__"obj/salt");
        salt->move(this_object());
     }
	set("already",1);
}


void reset(){
	::reset();
	if (!random(20))
		set("already",0);
}
