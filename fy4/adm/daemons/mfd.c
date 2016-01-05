// /adm/daemons/mfd.c
// written by akuma for magic find
// 2003-7-19
// version 0.9
// ��������ˣ��Ͳ���幫ʽ������
// ���У����Լӳɺ�imbueû��Ū��
#include <ansi.h>
int time=0;
void modify_vo(object,int,string);
mapping types = ([
	"cloth":	"����",
	"spear":	"��ǹ",
]);
mapping attr_types = ([
	"strength":	"����",
	"courage":	"����",
	"intelligence":	"����",
	"spirituality":	"����",
	"composure":	"����",
	"constitution":	"����",
	"karma":	"��Ե",
]);
	
string* lv_attr=({"���������","���ӵ�","��ͨ��","�߼���","������","�񻰰��"});
string* lv_color=({
	HIY,//������	
	HIG,//���Լӳ�	
	MAG,//û������
	BLU,//������
});
	
void create()
{
        seteuid(getuid());

}

object new_vo(int lv,string type)
{
	string file;
	object newvo;
	//����Ǵ��������
	if( undefinedp(types[type]) )
	{
		newvo=new("/obj/money/coin");
		return newvo;
	}
	//���ʱ����̫С��
	if( time() - time < 60 )
	{
		newvo=new("/std/vobase/"+type);
		return newvo;
	}
	//����
	time=time();
	file=sprintf("/vo/%s/%d",type,time());
	call_other(file,"???");
	// nobody would delete the sentense below
	write("");
	newvo=new(file);
	modify_vo(newvo,lv,type);
	CHANNEL_D->do_channel( this_object(), "sys","CREATE ONE VO FOR MF");
	return newvo;
}

void modify_vo(object newvo,int lv,string type)
{
	string name;
	int namelv;
	int rand;
	//��������	
	namelv=lv/10;
	if(namelv<0) namelv=0;
	if(namelv>sizeof(lv_attr)-1) namelv=sizeof(lv_attr)-1;
	name=lv_attr[namelv]+types[type];
	//��ʲô���ԣ�
	
	rand=(random(10));//3-9���ǵ͹������ԡ�������
	if(rand==0)//�Ǹ߹�����
	{
		if(type=="cloth")//||type="xxx")
		{
			newvo->set("armor_prop/armor", 10+lv+random(random(lv)));
		}
		if(type=="spear")//||type="xxx")
		{
			newvo->set("weapon_prop/damage", 10+lv+random(random(lv)));
		}

		newvo->set("value",lv*255);
		name=lv_color[0]+name+NOR;
	}		

	else if(rand==1)//���Լӳ�
	{
		if(type=="cloth")//||type="xxx")
		{
			newvo->set("armor_prop/armor", 10+lv);
		}
		if(type=="spear")//||type="xxx")
		{
			newvo->set("weapon_prop/damage", 10+lv);
		}
		//�������
//����û��д����
		newvo->set("armor_prop/intelligence",1);
//�����޸�
		//
		newvo->set("value",lv*288);
		name=lv_color[1]+name+NOR;
	}		
	else if(rand==2)//��û���Ե�
	{
		if(type=="cloth")//||type="xxx")
		{
			newvo->set("armor_prop/armor", 10+lv);
		}
		if(type=="spear")//||type="xxx")
		{
			newvo->set("weapon_prop/damage", 10+lv);
		}

		newvo->set("value",lv*222);

		name=lv_color[2]+name+NOR;
	}		
	else//low 
	{
		if(type=="cloth")//||type="xxx")
		{
			newvo->set("armor_prop/armor", 10+lv-random(random(lv)));
		}
		if(type=="spear")//||type="xxx")
		{
			newvo->set("weapon_prop/damage", 10+lv-random(random(lv)));
		}

		newvo->set("value",lv*188);

		name=lv_color[3]+name+NOR;

	}
	
	newvo->set("name",name);
	newvo->save();
}

void change_vo(object vo,mixed xx)
{
	//do what ne?
}