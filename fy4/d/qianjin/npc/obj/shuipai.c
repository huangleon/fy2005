
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("ˮ���", ({ "shuiyu" , "���"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����赣�������˸���ˮ���֣�
������Щ��ֵĻ��ƣ���ֻ����һ����赣����Ѿ��е�һ�������������
��赲�ʱ��������ɫ�Ĺ�ã���ƺ�Ҫ�����⼸�Ǻ�赣��������壩\n");
		set("value", 1);
	}
}


void init()
{
  	if(this_player()==environment())
  		add_action("do_combine","combine");
}

int do_combine()
{
	int i,yue=0,liu=0,xue=0,nu=0,cao=0,hua=0,jiu=0;
	object jade,me, *inv;
	object yuebi,liubi,xuebi,nubi,caobi,huabi,jiubi;
	me = this_player();
	inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
                {
			if(inv[i]->query("name") == "�����") {yue = 1; yuebi = inv[i];}
                        if(inv[i]->query("name") == "�����") {liu = 1; liubi = inv[i];}
                        if(inv[i]->query("name") == "ѩ���") {xue = 1; xuebi = inv[i];}
                        if(inv[i]->query("name") == "Ů���") {nu = 1;  nubi = inv[i];}
                        if(inv[i]->query("name") == "�����") {cao = 1; caobi = inv[i];}
                        if(inv[i]->query("name") == "�����") {hua = 1; huabi = inv[i];}
                        if(inv[i]->query("name") == "�����") {jiu = 1; jiubi = inv[i];}
		}
	if( yue && liu && xue && nu && cao && hua && jiu )
	{
		destruct(yuebi);
	        destruct(liubi);
	        destruct(xuebi);
	        destruct(nubi);
	        destruct(caobi);
	        destruct(huabi);
	        destruct(jiubi);
		jade = new(BOOKS"force_120");
		jade->move(me);
	message_vision("$N������ļ�����走�Ū�˼��£������꣢һ������赺�һ��\n",this_player());
	REWARD_D->riddle_done(this_player(),"������", 20, 1);
	
	destruct(this_object());

	}
	else 
		message_vision("$N������ļ�����走�Ū�˼��¡�\n",this_player());

	return 1;
}
