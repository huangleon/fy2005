#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name( BLK "��������" NOR, ({ "che" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("no_drop",1);
                set("no_get",1);
                set("timestamp","clscgcm");
                set("owner","cherub");
                set("rigidity",200);
		set("material", "iron");
		set("long", "����һ�����λεĵ������������ᡣ\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	::init_blade(30);
}

string query_save_file()
{
        string id;

        id = query("owner");
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s/%s", id[0],id, id+"."+query("timestamp"));
}

int save()
{
        string file;
        string equipped;
        int result;
        if( stringp(file = this_object()->query_save_file()) ) {
                equipped = (string)query("equipped");
                delete("equipped");
                assure_file(file+ __SAVE_EXTENSION__);
                result = save_object(file,1);
                set("equipped",equipped);
                return result;
        }
        return 0;
}
int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
        if(restore_object(file))
        {
                set_weight(query("weight"));
                return 1;
        }
        return 0;
}

