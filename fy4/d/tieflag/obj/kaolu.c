//kaolu.c
inherit ITEM;
void create()
{
    set_name("����С��¯", ({ "kaolu" }) );
    set_weight(10000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("value", 5);
            set("material", "stone");
            set("long", "һ�������Ƴɵ�С��¯�����ƺ�������������������Щʲô\n");
          }
//    ::init_item();
}
void init()
{
 add_action("do_kao","kao");
 add_action("do_kao","fry");
}                             

int do_kao(string arg)
{
        object me;
        object tar;
        object meat;
        string name;
        int decayed;
        me = this_player();
        if( !arg || arg == "")
           return notify_fail("�㿾ʲô��\n");
        if(!objectp(tar = present(arg, me)) )
           return notify_fail("�㿾ʲô��\n");
        if(tar->is_character() && !tar->is_corpse())
           return notify_fail("��...���������к���֮�£��㻹�������������ɣ�\n");
        if( !tar->is_character() && !tar->is_corpse())
           return notify_fail("�����㲻���Կ��Ķ�����\n");
        if( tar->is_corpse())
        {
           name=tar->query("name");
           name=replace_string(name,"һ��","");
           name=replace_string(name,"��ʬ��","");
           if (name!="����")         
           {
              decayed=0;
              name="��"+name+"��";
           }
           else
           {
               name="���õĿ���";
               decayed=1;
           }
           meat = new(__DIR__"meat");
           meat->set("name",name);
           meat->set("decayed",decayed);
           meat->move(me);
        }
        message_vision("$N��$n���ϵ������˼�Ƭ�ŵ�С��¯�һ����ͳ���һ��������Ŀ��⴮��\n", me, tar);     
        tar->add("fried",1);
        if (tar->query("fried") > 2) {
        	tell_object(me,tar->name()+"���ⶼ���������ˣ�\n");
        	tar->move(environment(me));
        	destruct(tar);
        }
        return 1;
}
