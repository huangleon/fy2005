inherit ITEM;
void create()
{
        set_name("�������", ({ "necromancy_book" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"�����������ؼ�                        
\n"                );
                set("value", 260);
                set("material", "paper");
        }
    ::init_item();
}
void init()
{
  if(this_player()==environment())
  add_action("do_study","study");
}
int do_study(string arg)
{
        object me,ob;
	int sena;
	int cps;
	string book;
        me = this_player();
	cps = random((int)me->query("cps"));
       if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
                return notify_fail("ָ���ʽ��study <��> <������>\n");
        if( (string)book != "necromancy_book")
                return notify_fail("��Ҫ��ʲ�᣿\n");
        if(!objectp(ob = present(book, me)) )
                return notify_fail("��Ҫ��ʲ�᣿\n");
	tell_object(this_player(),"���Ȼ�Ǳ��������飡��\n");

	return 1;
}
