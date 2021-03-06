/*
 * Copyright (C) 2021 Red Hat
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#include "config.h"

#include "backends/native/meta-kms-impl-device-dummy.h"

struct _MetaKmsImplDeviceDummy
{
  MetaKmsImplDevice parent;
};

static void
initable_iface_init (GInitableIface *iface);

G_DEFINE_TYPE_WITH_CODE (MetaKmsImplDeviceDummy, meta_kms_impl_device_dummy,
                         META_TYPE_KMS_IMPL_DEVICE,
                         G_IMPLEMENT_INTERFACE (G_TYPE_INITABLE,
                                                initable_iface_init))

static void
meta_kms_impl_device_dummy_discard_pending_page_flips (MetaKmsImplDevice *impl_device)
{
}

static void
meta_kms_impl_device_dummy_init (MetaKmsImplDeviceDummy *impl_device_dummy)
{
}

static gboolean
meta_kms_impl_device_dummy_initable_init (GInitable     *initable,
                                          GCancellable  *cancellable,
                                          GError       **error)
{
  return TRUE;
}

static void
initable_iface_init (GInitableIface *iface)
{
  iface->init = meta_kms_impl_device_dummy_initable_init;
}

static void
meta_kms_impl_device_dummy_class_init (MetaKmsImplDeviceDummyClass *klass)
{
  MetaKmsImplDeviceClass *impl_device_class =
    META_KMS_IMPL_DEVICE_CLASS (klass);

  impl_device_class->discard_pending_page_flips =
    meta_kms_impl_device_dummy_discard_pending_page_flips;
}
