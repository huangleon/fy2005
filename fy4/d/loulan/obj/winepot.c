inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("���ƾƺ�", ({ "wine pot" , "winepot"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����Ƶĵ��ƺ�����˵��ս��ʱ��
����ƴ�ʦ���ʦ�ɼ�ǧ��Ϭţ�ǣ��Ϲ�����ͽ���ͭ�������
���������Ƴɡ��ϱ߻�����Щ��ֵĻ��ơ���˵�ų����µ�һ��
��ġ���ȸ������ֻ����ֻ�ƺ����ܵ���������x����\n");
		set("value", 1);
	}
}

void init()
{
//	if(this_player()==environment())
	add_action("do_mix","mix");
}

int do_mix()
{
	int i,old,wolf,zhu,nu,gao,jian,dong;
	object peacock,me,*inv;
	object oldwine,wolfwine,zhuwine,nuwine,gaowine,jianwine,dongwine;
	me = this_player();
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		if((inv[i]->query("name") == "�ų���")&&(inv[i]->query("liquid/name") == "�ų���"))
		{old = 1; oldwine = inv[i];}
		if((inv[i]->query("name") == RED"�Ǿƴ�"NOR)&&(inv[i]->query("liquid/name") == "�Ǿ�"))
		{wolf = 1; wolfwine = inv[i];} 
		if((inv[i]->query("name") == "��Ҷ��ƴ�")&&(inv[i]->query("liquid/name") == "��Ҷ��"))
		{zhu = 1; zhuwine = inv[i];}
		if((inv[i]->query("name") == "����Ů����")&&(inv[i]->query("liquid/name") == "����Ů����"))
		{nu = 1;  nuwine = inv[i];}
		
		if((inv[i]->query("name") == "�����")&&(inv[i]->query("liquid/name") == "�����"))
		{gao = 1; gaowine = inv[i];}
		
		if((inv[i]->query("name") == "���ϴ��ƴ�")&&(inv[i]->query("liquid/name") == "���ϴ�"))
		{jian = 1; jianwine = inv[i];}
		if((inv[i]->query("name") == "����")&&(inv[i]->query("liquid/name") == "����"))
		{dong = 1; dongwine = inv[i];}
	}
	if( old==1 && wolf==1 && zhu==1 && nu==1 && gao==1 && jian==1 && dong==1 )
	{
			destruct(oldwine);
	        destruct(wolfwine);
	        destruct(zhuwine);
	        destruct(nuwine);
	        destruct(gaowine);
	        destruct(jianwine);
	        destruct(dongwine); 
        	peacock = new("/d/loulan/obj/bottle");
			peacock->move(me);
			message_vision("$N�����ϴ�����������С������ĵ������ƾƺ������Ƴ�һ��������\n��ġ���ȸ��������\n",this_player());
		    REWARD_D->riddle_done( this_player(),"��ȸ����",10, 1);
	        destruct(this_object());
	}
	else 
		message_vision("$N�Ѿ��ƾƺ���Ū�˼��£������ƺ�ȱ�ٵ���ϣ�ʲôҲ����������\n",this_player());
	return 1;
}
