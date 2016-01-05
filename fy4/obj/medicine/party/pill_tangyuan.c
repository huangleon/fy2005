inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(WHT"��Բ"NOR , ({ "tang yuan" }) );
	set_weight(6);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  		set("long", YEL"���ֹ������ڣ�������Ŵ�׷۴��������󣬳���������ɿڣ����з�Ȥ��\n"NOR);
        	set("unit", "��");
        	set("lore",1);
        	set("value", 3);
		set("food_remaining", 1);
		set("food_supply", 1);
		set("material", "food");
	}
	::init_item();
}


int finish_eat()
{
	mapping buff1,buff2,buff3;
	object me = this_player();
	string bufftype,type,name,msg;
	int amount,sf,n,n2,n3;
	
  string *list = ({ "gin" , "kee" , "sen" , "atman" , "force" , "mana" });
  string *typelist = ({ "gks" , "gks" , "gks" , "fma" , "fma" , "fma" });
  int *specialfunc = ({ 1 , 1 , 1 , 3 , 3 , 3 });
  int  *list_m = ({ 2000, 2000, 2000, 600 ,600 ,600 });
  string *list_c_n = ( {"��","��","��","��","��","��" });
  string *list_c = ( {"����","��Ѫ","����","����","����","����" });

	msg = GRN "$N��ʱ���û���ů�⣺�������Ҹ���\n"NOR;
	
	if (ANNIE_D->check_buff(me,"gks") || ANNIE_D->check_buff(me,"fma"))	{// it won't show up..just eat it.
  	//tell_object(me,CYN"��ζ���档\n"NOR);
		return notify_fail("��ζ���档\n"); 
	}
  n = random(sizeof(list));
  type = typelist[n];
  
  bufftype = list[n];
  amount = list_m[n];
  name = list_c_n[n];
  sf = specialfunc[n];
  
	buff1 =
	([
		"caster":me,
		"who": 	me,
		"type":	type,
		"att":	"bless",
		"name":	"��Բ��"+name,
		"buff1":bufftype,
		"buff1_c":amount,
		"time":  10800 ,
		"buff_msg":msg,
		//"disa_msg": "",
		"special_func":sf,
	]);
  ANNIE_D->buffup(buff1);      
  tell_object(me,CYN"�����"+ list_c[n] + "�����"+ amount + "�㣩\n"NOR);
    
  n2=n;
  
  while(n2==n) {
  	n = random(sizeof(list));
  }

  type = typelist[n];
  bufftype = list[n];
  amount = list_m[n];
  name = list_c_n[n];
  sf = specialfunc[n];

  buff2 =
	([
		"caster":me,
		"who": 	me,
		"type":	type,
		"att":	"bless",
		"name":	"��Բ��"+name,
		"buff1":bufftype,
		"buff1_c":amount,
		"time":  10800 ,
		"buff_msg":"",
		"special_func":sf,
	]);
  ANNIE_D->buffup(buff2);      
  tell_object(me,CYN"�����"+ list_c[n] + "�����"+ amount + "�㣩\n"NOR);

  n3=n;
  
  while(n3==n || n2==n) {
  	n = random(sizeof(list));
  }

  type = typelist[n];
  bufftype = list[n];
  amount = list_m[n];
  name = list_c_n[n];
  sf = specialfunc[n];

  buff3 =
	([
		"caster":me,
		"who": 	me,
		"type":	type,
		"att":	"bless",
		"name":	"��Բ��"+name,
		"buff1":bufftype,
		"buff1_c":amount,
		"time":  10800 ,
		"buff_msg":"",
		"special_func":sf,
	]);
  ANNIE_D->buffup(buff3);      
  tell_object(me,CYN"�����"+ list_c[n] + "�����"+ amount + "�㣩\n"NOR);


  destruct(this_object());
 	return 1;
}
