inherit ITEM;
void create()
{
	set_name("ǽ", ({ "wall" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"һ��ѩ�׵�ǽ�ڣ����������������Ƶ����Ρ�\n");
		set("no_shown",1);
                set("material", "stone");
		set("no_get",1);
		set("no_drop",1);
		set("skill", ([
			"name": 		"ill-quan",	
			"exp_required":		1000,		
			"sen_cost":		30,	
			"difficulty":	20,	
			"max_skill":	50		
		]) );
	}
    ::init_item();
}
void init()
{
  add_action("do_study","study");
}
int do_study(string arg)
{
    string book;
    string sena;
    if(!arg || sscanf(arg, "%s %d", book, sena)!=2 ) return 0;
    if (book == "wall" || book  == "ǽ")
     if (!this_player()->query_temp("mark/arraying"))
      { 
        tell_object(this_player(),"���������Ů����ʽ������ᲡάĦȭ\n");
        return 1;
      }
    return 0;
}