#include <ansi.h>

inherit ROOM;

int check_inv(object ob);

void setup()
{
    set("no_fight",1);
    ::setup();
}

void init()
{
    object ob;

    ob=this_player();
    if(interactive(ob)/* && !wizardp(ob)*/)
        if(check_inv(ob)==0)
        {
            tell_object(ob,HIY+query("short")+"������ĵط�����ֻ�ܴ�ʳ���ˮ������\n"+
                        HIB+"�㱻���˳�����\n"+NOR);
            ob->move(query("exits")[query("throw_exit")],1);
        }
}

int check_inv(object ob)
{
    int i;
    object *inv;
    
    inv = all_inventory(ob);
    for(i=0; i<sizeof(inv); i++)
    {
        string id=inv[i]->query("id");
        //only allow food/drink/cloth/money/self-made things
        if((inv[i]->query("food_remaining") == 0) &&
           (inv[i]->query("liquid") ==0) &&
           (inv[i]->query("name") != "����") &&
           (id != "gold") && (id != "silver") && (id != "coin") &&
           (id != "thousand-cash") &&
           (inv[i]->query("owner") != ob->query("id"))
           )
            return 0;
    }
    return 1;
}
