#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("����", ({ "woodcase" , "case"}) );
    set_weight(500);
    set_max_encumbrance(40000);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "��");
	set("long",
	  "����һ������ͨͨ�����ӡ����������make����remake��������\n");
    }
    ::init_item();
}
int is_container() { return 1; }
void init()
{
    add_action("do_make","make");
}

int do_make(string arg)
{
    object me;
    object obj;
    me=this_player();
    if(environment()==this_player() && (int) this_player()->query("sen")>250)
    {               
	if(!arg) return 0;
	{
	    if(arg=="axe")        {obj=new(__DIR__"cmaxe");obj->move(me);
		write("�㽫���е����Ӵ򿪣������е����ƴ����һ�Ѹ���\n");destruct(this_object());}
	    if(arg=="blade")      {obj=new(__DIR__"cmblade");obj->move(me);
		write("�㽫���е����Ӵ򿪣������е����ƴ����һ�ѵ���\n");destruct(this_object());}             
	    if(arg=="dagger")     {obj=new(__DIR__"cmdagger");obj->move(me);
		write("�㽫���е����Ӵ򿪣������е����ƴ����һ��ذ�ס�\n");destruct(this_object());}
	    if(arg=="claw")       {obj=new(__DIR__"cmclaw");obj->move(me);
		write("�㽫���е����Ӵ򿪣������е����ƴ����һ��צ�ӡ�\n");destruct(this_object());}
	    if(arg=="hammer")     {obj=new(__DIR__"cmhammer");obj->move(me);
		write("�㽫���е����Ӵ򿪣������е����ƴ����һ�Ѵ���\n");destruct(this_object());}
	    if(arg=="staff")      {obj=new(__DIR__"cmstaff");obj->move(me);
		write("�㽫���е����Ӵ򿪣������е����ƴ����һ���ȡ�\n");destruct(this_object());}   
	    if(arg=="sword")      {obj=new(__DIR__"cmsword");obj->move(me);  
		write("�㽫���е����Ӵ򿪣������е����ƴ����һ�ѽ���\n");destruct(this_object());}
	    if(arg=="whip")       {obj=new(__DIR__"cmwhip");obj->move(me);
		write("�㽫���е����Ӵ򿪣������е����ƴ����һ�ѱޡ�\n");destruct(this_object());}             
	    else tell_object(me, "��Ҫ��ʲô������\n");
	}
	return 1;
    }
    return 0;
}          
